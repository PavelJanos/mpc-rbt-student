#!/bin/bash
export LOG_LEVEL=1
# Přesun do složky s binárkami
cd "$(dirname "$0")/build"

# Spuštění sender_node s config.json
exec ./sender_node ../config.json
