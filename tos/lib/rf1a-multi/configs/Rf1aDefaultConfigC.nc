module Rf1aDefaultConfigC {
  provides interface Rf1aConfigure;
} implementation {
  async command const rf1a_config_t* Rf1aConfigure.getConfiguration(){
    return &rf1a_default_config;
  }
  async command void Rf1aConfigure.preConfigure() { }
  async command void Rf1aConfigure.postConfigure() { }
  async command void Rf1aConfigure.preUnconfigure() { }
  async command void Rf1aConfigure.postUnconfigure() { }

}
