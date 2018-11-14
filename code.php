<?
session_start();
session_register("secret_number");

function mt() {
	list($usec, $sec) = explode(' ', microtime());
	return (float) $sec + ((float) $usec * 100000);
	}

header("Content-type: image/png");
$im=@imagecreate(101, 26);
$w=imagecolorallocate($im, 255, 255, 255);
$g1=imagecolorallocate($im, 192, 192, 192);
$g2=imagecolorallocate($im, 64,64,64);
srand(mt());$c1=rand(0,128);srand(mt());$c2=rand(0,128);srand(mt());$c3=rand(0,128);$cl1=imagecolorallocate($im,$c1,$c2,$c3);
srand(mt());$c1=rand(0,128);srand(mt());$c2=rand(0,128);srand(mt());$c3=rand(0,128);$cl2=imagecolorallocate($im,$c1,$c2,$c3);
srand(mt());$c1=rand(0,128);srand(mt());$c2=rand(0,128);srand(mt());$c3=rand(0,128);$cl3=imagecolorallocate($im,$c1,$c2,$c3);
srand(mt());$c1=rand(0,128);srand(mt());$c2=rand(0,128);srand(mt());$c3=rand(0,128);$cl4=imagecolorallocate($im,$c1,$c2,$c3);

for ($i=0;$i<=100;$i+=5) imageline($im,$i,0,$i,25,$g1);
for ($i=0;$i<=25;$i+=5) imageline($im,0,$i,100,$i,$g1);

imagestring($im, 5, 0+rand(0,10), 5+rand(-5,5), substr($_SESSION["secret_number"],0,1), $cl1);
imagestring($im, 5, 25+rand(-10,10), 5+rand(-5,5), substr($_SESSION["secret_number"],1,1), $cl2);
imagestring($im, 5, 50+rand(-10,10), 5+rand(-5,5), substr($_SESSION["secret_number"],2,1), $cl3);
imagestring($im, 5, 75+rand(-10,10), 5+rand(-5,5), substr($_SESSION["secret_number"],3,1), $cl4);

for ($i=0;$i<2;$i++) imageline($im,rand(0,100),rand(0,25),rand(0,100),rand(0,25),$g2);

imagepng($im);
imagedestroy($im);
?>