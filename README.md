# fed-maze
MAZE COMPONENTS:

FED3_mazemodes.ino : upload to FED3 device for modes 1 and 2 (FF with CondStim for hab, dispenser with CondStim for experimental days)

arduinouno_beambreaktofed3.ino : if external circuit uses Arduino UNO, upload this code for beam breaks to send BNC signals out

qtpy_beambreaktofed3.ino : QTPY external circuit for beam breaks to send BNC signal to the FED device

qtpy_buttontofed3.ino : QTPY external circuit for manual button pressing to send BNC signal to the FED device

fed3dispenser.ino (STANDALONE DISPENSER CODE): upload to FED3 device for experimental days (BNC signal triggers 1 pellet to be dispensed at a time)

DATA ANALYSIS:
fed_extract_columns.py : this code allows you to upload both EXP1 and EXP2 FED files to append/extract necessary columns in order to graph pellet accumulation vs. time elapsed

biobserve_extract_columns.py : upload Biobserve file (from Emmie's saved configuration) with zone data to extract relevant columns to easily analyze visits in intervals of 5 minutes at a time
