#!bin/bash



mass=("100" "200" "300" "400" "500")
ctau=("1" "10" "50") 

#mass=("500")
#ctau=("5") 

printTitle=1
for ct in "${ctau[@]}"
  do
    for m in "${mass[@]}"
    do
	#echo "m="$m
	#echo "ctau="$ct

	root -l -b -q SignalContamination.C+"(\"$m\",\"$ct\")"

    done
done
