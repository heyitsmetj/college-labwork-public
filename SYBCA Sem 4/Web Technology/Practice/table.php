<!DOCTYPE html>
<html lang="en">

<head>
    <title>Prime List</title>
</head>

<body>
    <form action="table.php" method="post">
        Enter Rows:
        <input type="text" name="rows">
        Enter Columns:
        <input type="text" name="cols">
        <input type="submit" name="submit" value="Create">
        <br><br><br><br>
    </form>
</body>

</html>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") 
{
    if (isset($_POST["submit"])) 
    {
        $rows = $_POST["rows"];
        $cols = $_POST["cols"];

        echo "<table border = 5 cellspacing = 10px cellpadding = 10px>";
        for ($i=1; $i <= $cols; $i++) 
        { 
            echo"<tr>";
            for ($j=1; $j <= $rows; $j++) { 
                echo "<td>Column{$j} Row{$i}";
            }
            echo "<tr>";
        }
        echo "</table>";
    }
}

?>