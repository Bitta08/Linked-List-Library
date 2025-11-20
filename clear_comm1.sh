#!/bin/bash
# Script per estrarre i commenti da un file .h e salvare il codice pulito

# Controllo parametri
if [ $# -ne 2 ]; then
    echo "Uso: $0 file_input.h file_output_pulito.h"
    exit 1
fi

INPUT="$1"
OUTPUT="$2"
COMMENTI="comments_tmp.txt"

# Estrae tutti i commenti (// e /* */) e li salva in un file temporaneo
grep -oP '(//.*$|/\*.*?\*/)' "$INPUT" > "$COMMENTI"

# Rimuove i commenti dal file originale e salva nel file output
# Nota: sed -E per espressioni regolari estese
sed -E 's@//.*$@@g; s@/\*.*\*/@@g' "$INPUT" > "$OUTPUT"

# Opzionale: salva i commenti in un file separato
mv "$COMMENTI" "lll_comments.txt"

echo "Commenti salvati in lll_comments.txt"
echo "Codice pulito salvato in $OUTPUT"
