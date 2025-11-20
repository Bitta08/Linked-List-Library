#!/bin/bash
# strip_comments_perl.sh
# Estrae tutti i commenti da un file .h e li salva in un file separato,
# lasciando il codice pulito nel file di output.

if [ $# -ne 2 ]; then
    echo "Uso: $0 file_input.h file_output_pulito.h"
    exit 1
fi

INPUT="$1"
OUTPUT="$2"
COMMENTI="lll_comments.txt"

# Estrae tutti i commenti (multilinea e singola linea) e li salva
perl -0777 -ne 'while (/\/\/.*?$|\/\*.*?\*\//msg) { print "$&\n" }' "$INPUT" > "$COMMENTI"

# Rimuove tutti i commenti dal codice e salva in output
perl -0777 -pe 's/\/\/.*?$|\/\*.*?\*\///msg' "$INPUT" > "$OUTPUT"

echo "Commenti salvati in $COMMENTI"
echo "Codice pulito salvato in $OUTPUT"
