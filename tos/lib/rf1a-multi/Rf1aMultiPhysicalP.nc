generic module Rf1aMultiPhysicalP (char configSetIdentifier[]){
  provides interface Rf1aConfigure;
  provides interface Rf1aMulti;
  uses interface Rf1aConfigure as SubConfigure[uint8_t clientId] ;
  uses interface Get<uint16_t> as SubGet[uint8_t clientId];
} implementation {
  uint8_t currentClient = 0;

  command uint8_t Rf1aMulti.getNumConfigs(){
    return uniqueCount(configSetIdentifier);
  }

  command uint8_t Rf1aMulti.getConfig(){
    return currentClient;
  }

  command error_t Rf1aMulti.setConfig(uint8_t clientId){
    if(clientId > uniqueCount(configSetIdentifier)){
      return EINVAL;
    } else {
      atomic{
        currentClient = clientId;
      }
      //TODO: this should check for safety first
      return SUCCESS;
    }
  }

  command error_t Rf1aMulti.setConfigId(uint16_t id){
    uint8_t k;
    error_t rv;
    for(k = 0; k < (call Rf1aMulti.getNumConfigs()); k++){
      if( call SubGet.get[k]() == id){
        rv = call Rf1aMulti.setConfig(k);
        return rv;
      }
    }
    return EINVAL;
  }

  command uint16_t Rf1aMulti.getConfigId(){
    return call SubGet.get[currentClient]();
  }

  async command const rf1a_config_t* Rf1aConfigure.getConfiguration(){
    return call SubConfigure.getConfiguration[currentClient]();
  }
  async command void Rf1aConfigure.preConfigure(){
    call SubConfigure.preConfigure[currentClient]();
  }
  async command void Rf1aConfigure.postConfigure(){
    call SubConfigure.postConfigure[currentClient]();
  }
  async command void Rf1aConfigure.preUnconfigure(){
    call SubConfigure.preUnconfigure[currentClient]();
  }
  async command void Rf1aConfigure.postUnconfigure(){
    call SubConfigure.postUnconfigure[currentClient]();
  }

  default async command const rf1a_config_t* SubConfigure.getConfiguration[uint8_t clientId](){
    return NULL;
  }
  default command uint16_t SubGet.get[uint8_t clientId](){ return 0xFFFF;}
  default async command void SubConfigure.preConfigure[uint8_t clientId](){ }
  default async command void SubConfigure.postConfigure[uint8_t clientId](){ } 
  default async command void SubConfigure.preUnconfigure[uint8_t clientId](){ } 
  default async command void SubConfigure.postUnconfigure[uint8_t clientId](){ }
}
