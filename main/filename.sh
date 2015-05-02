mydate=$(stat /var/www/my30secvid.mp4 | grep 'Change: ' | cut -f 2 -d ' ')
mytime=$(stat /var/www/my30secvid.mp4 | grep 'Change: ' | cut -f 3 -d ' ')
filename=$mydate+$mytime
echo $filename
mail -s $filename -a /var/www/my30secvid.mp4 neville.andrade@gmail.com < time.txt
