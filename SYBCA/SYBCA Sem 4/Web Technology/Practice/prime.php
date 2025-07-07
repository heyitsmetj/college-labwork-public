<!DOCTYPE html>
<html lang="en">

<head>
    <title>Prime List</title>
</head>

<body>
    <form action="prime.php" method="post">
        Enter Prime Numbers:
        <input type="text" name="nums" placeholder="Ex.- 1, 2, 3, 4...">
        <input type="submit" name="submit" value="Check">
    </form>
</body>

</html>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") 
{
    if (isset($_POST["submit"])) 
    {
        $num = $_POST["nums"];
        $num = explode(",", $num);

        echo "Your Numbers: ";
        foreach ($num as $x) 
        {
            echo $x . " ";
        }

        echo "<br>Prime Numbers: ";
        foreach ($num as $x) 
        {
            $flag = True;

            for ($i = 2; $i < $x; $i++) 
            {
                if ($x % $i == 0) 
                {
                    $flag = False;
                    break;
                }
            }

            if($flag)
            {
                echo $x." ";
            }
        }
    }
}


?>