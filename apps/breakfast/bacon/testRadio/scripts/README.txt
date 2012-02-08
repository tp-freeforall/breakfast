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
