find Library Test -type f | while read FILE
do
    nkf -w --overwrite ${FILE}
done
