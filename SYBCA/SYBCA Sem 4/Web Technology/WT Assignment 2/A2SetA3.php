<!DOCTYPE html>
<html lang="en">

<head>
    <title>A2SetA3</title>
</head>

<body>
    <form action="A2SetA3.php" method="post">
        Enter a string:
        <input type="text" name="string">
        <input type="submit" name = "submit" value="Check">
    </form>
</body>

</html>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if(isset($_POST["submit"])){
    $str = $_POST["string"];

    echo "Your String: " . $str;
    echo "<br>Reversed String: " . strrev($str);

    if (strrev($str) == $str) {
        echo "<br>{$str} is a Palindrome.";
    } else {
        echo "<br><br>{$str} is NOT a Palindrome.";
    }
}
}
?>