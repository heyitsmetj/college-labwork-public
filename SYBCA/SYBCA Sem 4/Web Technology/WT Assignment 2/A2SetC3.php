<!DOCTYPE html>
<html lang="en">

<head>
    <title>A2SetC3</title>
    <style>

        form {
            margin-bottom: 20px;
        }

        table {
            border-collapse: collapse;
            width: 100%;
            margin-top: 20px;
        }

        th,
        td {
            border: 1px solid #ccc;
            padding: 10px;
            text-align: center;
        }
    </style>
</head>

<body>
    <h1>String Operations</h1>
    <form method="post">
        <label for="string1">Enter First String:</label>
        <input type="text" id="string1" name="string1" required><br><br>

        <label for="string2">Enter Second String:</label>
        <input type="text" id="string2" name="string2" required><br><br>

        <label for="position">Enter the position to reverse characters from the first string:</label>
        <input type="number" id="position" name="position" required min="0">

        <br><br>Choose Comparison Method:<br><br>

        <input type="radio" id="equals" name="comparison" value="equals" required>== Operator
        
        <input type="radio" id="strcmp" name="comparison" value="strcmp">strcmp Function
        <br><br>
        <button type="submit" name="submit">Perform Operations</button>
    </form>

    <?php
    if ($_SERVER['REQUEST_METHOD'] === 'POST' && isset($_POST['submit'])) 
    {
        $string1 = $_POST['string1'];
        $string2 = $_POST['string2'];
        $position = intval($_POST['position']);
        $comparisonMethod = $_POST['comparison'];

        if ($position < 0 || $position > strlen($string1)) 
        {
            echo "<p style='color: red;'>Invalid position! Please enter a value between 0 and " . strlen($string1) . ".</p>";
            exit;
        }

        $comparisonResult = '';
        
        if ($comparisonMethod === 'equals') 
        {
            $comparisonResult = ($string1 == $string2) ? "Strings are equal (==)" : "Strings are not equal (==)";
        } 
        
        elseif ($comparisonMethod === 'strcmp') 
        {
            $result = strcmp($string1, $string2);
            if ($result === 0) 
            {
                $comparisonResult = "Strings are equal (strcmp)";
            } 
            elseif ($result < 0) 
            {
                $comparisonResult = "First string is less than the second string (strcmp)";
            } 
            else 
            {
                $comparisonResult = "First string is greater than the second string (strcmp)";
            }
        }

        $appendedString = $string1 . $string2;

        $partToReverse = substr($string1, $position);
        $reversedPart = strrev($partToReverse);
        $finalString = substr($string1, 0, $position) . $reversedPart;

        echo "<h2>Results:</h2>";
        echo "<table>
                <tr>
                    <th>Operation</th><th>Result</th>
                </tr>
                <tr>
                    <td>Comparison Result</td><td>$comparisonResult</td>
                </tr>
                <tr>
                    <td>Appended String</td><td>$appendedString</td>
                </tr>
                <tr>
                    <td>Final String (Reversed Part)</td><td>$finalString</td>
                </tr>
              </table>";
    }
    ?>
</body>

</html>