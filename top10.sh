#!/bin/bash

if [[ ! -r "$1" ]]; then
  echo "Error"
  exit 1
fi

echo "| Area | Doses administered |"
echo "| :--------- | --------: |"
awk -F',' '$7 == "All" {print $2"," $10}' "$1" | sort -t, -k2 -nr | head -n 10 | sed 's/^/|/; s/,/|/; s/$/|/'







