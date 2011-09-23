/* Copyright (c) 2010 People Power Co.
 * All rights reserved.
 *
 * This open source code was developed with funding from People Power Company
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the
 *   distribution.
 * - Neither the name of the People Power Corporation nor the names of
 *   its contributors may be used to endorse or promote products derived
 *   from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE
 * PEOPLE POWER CO. OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE
 *
 */

/** A utility interface that allows protocols to intercept and modify
 * data just prior to transmission.
 *
 * @author Peter A. Bigot <pab@peoplepowerco.com>
 */
interface Rf1aTransmitFragment {
  /** Validate the requested length of data ready to be transmitted.
   *
   * This command is invoked by a physical-layer radio when it needs
   * to place data in the radio's transmit buffer.
   *
   * In most situations, a reasonable decision is to just return
   * count.
   *
   * @param count The maximum number of octets the radio is prepared
   * to be told to transmit in the next block.  Will be positive.
   *
   * @return The number of octets the radio should transmit in the
   * next block.  A value of zero indicates that no data is
   * immediately available, and the radio should request again later.
   * The returned value must not exceed the provided count.  */
  async command unsigned int transmitReadyCount (unsigned int count);

  /** Provide the data to be transmitted.
   *
   * This is invoked to locate the data that is to be transmitted in
   * the next block.  It allows gather-style message transmission.
   * The incoming count will be positive, and no greater than the
   * value of the transmitReadyCount returned prior to invoking this.
   * The invocation must either return a pointer to a block of at
   * least count octets, or 0 to indicate that the transmission should
   * be aborted.
   *
   * @param count The number of octets that must be made available
   * for transmission.
   *
   * @return A pointer to a sequence of octets of length count, or
   * null to abort the transmission.  */
  async command const uint8_t* transmitData (unsigned int count);
}

/* 
 * Local Variables:
 * mode: c
 * End:
 */
