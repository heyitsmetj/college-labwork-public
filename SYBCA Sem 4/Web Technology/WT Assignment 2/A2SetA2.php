<!DOCTYPE html>
<html lang="en">

<head>
    <title>A2SetA2</title>
</head>

<body>
    <form action="A2SetA2.php" method="post">
        Enter a string to be reversed:
        <input type="text" name="string">
        <input type="submit" name = "submit" value="Reverse">
    </form>
</body>

</html>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") 
{
   if(isset($_POST["submit"])){
    $str = $_POST["string"];

    echo "Your String: " . $str;
    echo "<br>Reversed String: " . strrev($str);
}}
?>