cd Library
find . -type f | while read FILE
do
    nkf -w --overwrite ${FILE}
done
