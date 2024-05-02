#!/bin/bash

# Determine OS
OS="$(uname)"

# VS Code settings location for Mac and Linux in workspace
VSCODE_SETTINGS="./.vscode/settings.json"

# Choose settings file based on OS
if [ "$OS" == "Darwin" ]; then
    cp settingsMac.json "$VSCODE_SETTINGS"
elif [ "$OS" == "Linux" ]; then
    cp settingsLinux.json "$VSCODE_SETTINGS"
else
    echo "Unsupported OS"
fi