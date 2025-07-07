<!DOCTYPE html>
<html lang="en">
<head>
    <title>A3SetA1</title>
    <style>
        form{
            text-align: center;
        }
    </style>
</head>
<body>
    <form action="A3SetA1.php" method="post">
    <label for="input">Enter keys and values (key1:value1, key2:value2):</label><br>
    <input type="text" id="input" name="data" placeholder="key1:value1, key2:value2"><br>

        <br><br>
        Select Operation
        <select name="operation">
            <option value="None" selected>Please Select</option>
            <option value="keydisplay">Display Array with Keys</option>
            <option value="size">Display Size of the Array</option>
        </select><br><br>
        <input type="submit" value="Perform" name="submit">
    </form>
</body>
</html>
<?php
 if ($_SERVER['REQUEST_METHOD'] == 'POST' && isset($_POST['submit']))
 {
    $inputData = $_POST['data'];

    $pairs = explode(",", $inputData);
    $associativeArray = [];

    foreach ($pairs as $pair) 
    {
        list($key, $value) = explode(":", $pair);
        $associativeArray[trim($key)] = trim($value);
    }

    if($_POST["operation"] == "keydisplay")
    {
        echo "Associative Array:<br>";
        print_r($associativeArray);
    }
    elseif($_POST["operation"] == "size")
    {
        echo "Size of array: ", count($associativeArray);
    }
    else
    {
        echo '<h1 style = "color: red;">Please select an option!</h1>';
    }
 }
?>