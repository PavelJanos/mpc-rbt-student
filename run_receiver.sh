#!/bin/bash

export LOG_LEVEL=1
# Přesun do složky s binárkami
cd "$(dirname "$0")/build"

# Spuštění receiver_node s config.json
exec ./receiver_node ../config.json
