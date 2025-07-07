<!DOCTYPE html>
<html lang="en">

<head>
    <title>A2SetB1</title>
</head>

<body>
    <form action="A2SetB1.php" method="post">
        Enter a Number:
        <input type="text" name="string">
        <input type="submit" name="submit" value="Generate">
    </form>
</body>

</html>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST["submit"])) {

        $num = $_POST["string"];

        $numbers = array(
            "0" => "Zero",
            "1" => "One",
            "2" => "Two",
            "3" => "Three",
            "4" => "Four",
            "5" => "Five",
            "6" => "Six",
            "7" => "Seven",
            "8" => "Eight",
            "9" => "Nine"
        );


        echo "Your Number: " . $num;
        echo "<br>Result: ";
        
        for ($i=0; $i < strlen($num); $i++) 
        {
            echo $numbers[$num[$i]] . " ";
        }

        }
    }
?>