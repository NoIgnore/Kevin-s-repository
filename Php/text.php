<?php
 /*$a='QNKCDZO';
 //$a=240610708;
 $b='240610708'	;
 echo md5($a);
 echo '<br/>';
 echo md5($b);
 echo '<br/>';
 if ( $a !==  $b){
     echo "half success";
 }
 echo '<br/>';
 if(md5($a) === md5($b)){
	 echo "success";
 }*/
$a=md5('QNKCDZO');
echo $a;
echo '<br/>';
$f[]=2;
json_encode($f);
//echo $f;
echo '<br/>';
$b=md5(240610708);
echo $b;
echo '<br/>';
var_dump($a == $b);echo '<br/>';
var_dump($a === $b);echo '<br/>';
var_dump('QNKCDZO' !== 'qnkcdzo' );echo '<br/>';//ture
var_dump( md5('QNKCDZO') === md5('qnkcdzo') );echo '<br/>';//flase

echo md5('QNKCDZO');echo '<br/>';
echo md5('QNKCDZo');echo '<br/>';
echo md5(0),'<br/>';
$txt="Hello world!";
$x=5;
$y=10.532432;
echo $y,'<br/>';
echo 3/5,'<br/>';
echo 1/3;
//php可以直接定义flaot?
echo "<h2>PHP is very funny!</h2>";
echo <<<EOF
    <h1>MY</h1>
    <p>MY</p>
EOF;
// 结束需要独立一行且前后不能空格
$c = array(1, 2, array("a", "b", "c"));
var_dump($c);

?>

