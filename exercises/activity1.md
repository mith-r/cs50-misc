tail -n +3 billboard.tsv
sort -nr billboard.tsv
cut -f3 billboard.tsv
grep -c 'Justin Bieber' billboard.tsv (91)
cut -f3 billboard.tsv | sort | uniq | wc -l (13)

cut -f2 billboard.tsv
