Log files (e.g. from the testbed) contain TX and RX messages, mixed
together. Additionally, the serial port doesn't appear to be 100%
reliable (this has been an ongoing problem prior to bacon), garbling
some lines. In order to make pretty graphs with this data, we want to
load it into a database.

load.sh: takes as arguments a series of log file names. For each of
these, it cleans up the data and loads it into an sqlite database
(same name + .db suffix), which the R scripts talk to to make the
graphs.

It also validates the format with regular expressions (checksum would
be more robust, but is kind of a pain). 

radioPlots.R (not finished): Takes as argument a db file, produces
various plots (under figs/<db file name>/).
  - RSSI stability over time
  - others?

NOTE: 
The R scripts assume that the R odbc package is installed and the
sqlite odbc driver (libsqliteodbc and r-cran-rodbc in apt)


OUTDOOR TESTING
at transmitter location:
  - setup tripod
  - take GPS fix and record it.
for each receiver location:
  - set up tripod
  - hook up receivers to laptop at receiver location
  - turn on SA and wait for GPS fix
  - for each  transmitter
    - turn on relevant transmitter
    - take sample on SA, make a note of the time that it
      started/stopped
    - plug in receivers
      ./rxOnly.sh 60 /path/to/test/dir 
 
Back at the lab:
- copy files from SA USB stick to /path/to/sa/data
- run ./describeSA.sh /path/to/sa/data and figure out which files
  correspond to which test. 
- move the .ia files to the relevant test directory
- run
  ./processOutdoors.sh /path/to/processed/data [testDir...]
- This will create a sqlite database at the specified location with
  tables RSSI and PRR.

TODO: how to graph it
