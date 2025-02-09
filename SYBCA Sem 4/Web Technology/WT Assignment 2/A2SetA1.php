<!DOCTYPE html>
<html lang="en">

<head>
    <title>A2SetA1</title>
</head>

<body>
    <form action="A2SetA1.php" method="post">
        Enter a number:
        <input type="text" name="num">
        <input type="submit" name = "submit" value="Check">
    </form>
</body>

</html>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST["submit"])) {
        function fact($num)
        {
            $fact = 1;

            for ($i = 1; $i <= $num; $i++) {
                $fact *= $i;
            }

            return $fact;
        }

        $num = null;
        $num = (int)$_POST["num"];

        echo "Your number: " . $num;
        echo "<br>Factorial of number: " . fact($num);
    }
}
?>