#!/bin/bash
# extract_multiline_comments.sh
# Estrae solo i commenti multilinea /* ... */ da un file .h
# e li salva in un file separato con una riga vuota tra ciascuno.

if [ $# -ne 2 ]; then
    echo "Uso: $0 file_input.h file_output_commenti.h"
    exit 1
fi

INPUT="$1"
OUTPUT="$2"

# Estrae solo i commenti multilinea e aggiunge una riga vuota tra ciascuno
perl -0777 -ne 'while (/\/\*.*?\*\//msg) { print "$&\n\n" }' "$INPUT" > "$OUTPUT"

echo "Commenti multilinea salvati in $OUTPUT"
