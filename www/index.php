<html>
<head>
<title>Pi led control - From Berlin with Love</title>
</head>
<body>
<h1>Pi Relay Control App</h1>
<?php
$mysqli = new mysqli('localhost','root','ga01r4956','pi');
if ($mysqli->connect_error) 
{
 die('Connect Error ('. $mysqli->connect_error . ')' . $mysqli->connect_error);
}

?>

<?php
$result = $mysqli->query("select pinstatus from gpio where pinnumber = 17");
while($row = $result->fetch_assoc())
{
	print "<h2>" .$row["pinstatus"]."</h2>";
}
?>

<form action="index.php" method="POST">
<input type="hidden" name="action" value="insert" />
inputstatus: <input name="pinstatus" /><br/>
<input type ="submit"/>
</form>

<?php
if(isset($_REQUEST["action"]))
{
switch($_REQUEST["action"])
{
	case "insert":
	$SQL = "update gpio set pinstatus =";
	$SQL =$SQL.$_REQUEST["pinstatus"]." where pinnumber = 17;";
if($mysqli->query($SQL)==FALSE)
{
	printf("Error - Unable to update database ". $mysqli->error);
}
	break;
	case "delete";
		print "Delete function to be added";
	break;
}
}
$mysqli->close();
?>

</body>
</html>
