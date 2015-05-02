raspivid -w 800 -h 600 -t 30000 -fps 30 -o my30secvid.h264 #get video
MP4Box -add my30secvid.h264 my30secvid.mp4 #convert video
rm -f my30secvid.h264 #remove old file
cp my30secvid.mp4 /var/www
rm -f my30secvid.mp4
