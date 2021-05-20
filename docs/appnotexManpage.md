% APPNOTEX(1) appnotex 0.9.0
% Abir-Tx
% May 2021

# NAME
appnotex - Linux personal apps/packages quick terminal based note keeper which can be exported later

# SYNOPSIS
**appnotex**
**appnotex** [options]

# DESCRIPTION

**appnotex** is a terminal based small and very fast quick note taking app. Most of the time linux users takes notes about their new fav app or tool they have find so that info can be used later on in case of a reinstall or else. This is where **appnotex** comes really handy. It gives the abitlity to take the notes about an app without leaving the terminal and the saved information/notes can be exported to a text format easily with **--export** option.

# OPTIONS

**-h**, **--help**
: Prints the help menu

**-p**, **--print**
: Prints all the saved apps info in a nice format in runtime on the terminal from the **appnotex** app. This only prints or shows the saved info, it does not export info.

**-e**, **--export**
: Exports the saved apps info to a text file in current directory.

**-g**, **--general**
: Takes quick general notes other than apps notes. This invokes the **notex** app which comes with **appnotex** from **version 1.0.0**. This enables the user to take quick small notes.

**--printall**
: Prints all the saved data from both **appnotex** and **notex** app.

**-v**, **--version**
: Prints the apps current version and developement informations


# EXAMPLES

**appnotex**
: Fires up the main note taking wizard. issue this command anywhere in terminal after installation to quickly take notes

**appnotex -p**
: View all the informations/notes you have saved before

**appnotex --help**
: Get help about appnotex

# Bugs

Currently I am not aware of any bugs. If you find one please submit the bug report through this link - <https://github.com/Abir-Tx/AppNotEx/issues/new>

# FILES

- /usr/local/bin/appnotex           The main executable of the app
- $HOME/.local/share/appnotexlog    Log file of appnotex
- $HOME/.local/share/data.db        The database file which holds all the informations/notes

# Author

Mushfiqur Rahman Abir **(<https://www.github.com/abir-tx>)**

# COPYRIGHT

Copyright © 2021 Abir-Tx aka Mushfiqur Rahman Abir. License AGPL3.0: GNU Public version 3. This is a fee software: you are free to change and redistribute it. There is no **WARRANTY**, to the extent permitted by law.