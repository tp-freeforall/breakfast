/*
 * Interface for allowing a single radio stack to switch modulation
 * schemes/data rates/ etc. The available configurations are expected
 * to be defined at compile time. This interface provides a
 * streamlined mechanism for switching between them and 
 * ensuring that configurations are changed only when it's "safe"
 */
interface Rf1aMulti {
  /** @return Total number of configurations available */
  command uint8_t getNumConfigs();

  /** Set the active configuration index
   * @return FAIL if radio is not able to handle this config change at
   * the moment.
   */
  command error_t setConfig(uint8_t configId);

  /**
   * @return The index of the currently-active configuration.
   */
  command uint8_t getConfig();
  
  /**
   * @return the (hopefully) globally-unique ID of the
   * currently-active configuration
   */
  command uint16_t getConfigId();

  /**
   *  set the desired configuration by unique ID.
   *  @return SUCCESS if the specified ID was wired to at least one
   *  sub-configuration. Return EINVAL if it was not.
   */
  command error_t setConfigId(uint16_t id);
}
