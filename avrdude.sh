AVRDIR="/mnt/c/workspace/qmk/avr"

MODECMD='/mnt/c/Windows/System32/mode.com'
GET_COMPORT='/mnt/c/Windows/System32/reg.exe query HKLM\HARDWARE\DEVICEMAP\SERIALCOMM'

CONNECTED_COMPORT=$(${MODECMD}|grep -oE 'COM[0-9]+'| tr '\n' '|' | sed -e 's/|$//g')
echo "connected port: $CONNECTED_COMPORT"
TARGET_COMPORT=""

while [ "$TARGET_COMPORT" = "" ];do
    sleep 0.5
    printf "."
    if [ -z "$CONNECTED_COMPORT" ]; then
        TARGET_COMPORT=$(${GET_COMPORT}|grep -oE 'COM[0-9]+')
    else
        TARGET_COMPORT=$(${GET_COMPORT}|grep -vE "$CONNECTED_COMPORT"|grep -oE 'COM[0-9]+')
    fi
done

echo ""
echo "$TARGET_COMPORT"

${AVRDIR}/avrdude.exe -C ./avrdude.conf -c avr109 -p m32u4 -P "${TARGET_COMPORT}" -U flash:w:"$1"

