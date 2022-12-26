#!/bin/bash
#The software should accept two command line arguments: the path of the directory to copy and the name of the path in which to save the backup.
#If the backup is repeated, the program should only recopy files that have changed since the previous time they were backed up.
#The program should ignore subdirectories and just backup files in the specified directory.
folder1=$1
folder2=$2

if [ -f $folder1 ] && [ -f $folder2 ]; then    #ensures that we only have two arguments
    echo "Usage: $0 SOURCE DESTINATION"
    exit 0;
fi

if [ ! -d "$folder2" ]; then     #The line with ! -d verifies that the directory from second argument exists
    echo "The file does not exist or isn't a directory"
    exit 0;
fi

cp -v -u $folder1/* $folder2 2>/dev/null