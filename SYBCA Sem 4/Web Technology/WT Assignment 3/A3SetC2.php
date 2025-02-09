<?php
session_start();

if (!isset($_SESSION['array'])) 
{
    $_SESSION['array'] = [];
}

if ($_SERVER["REQUEST_METHOD"] == "POST") 
{
    $action = $_POST['action'];

    if ($action == "set_array") 
    {
        $_SESSION['array'] = array_map('trim', explode(',', $_POST['array']));
        $message = "Array has been set.";
    } 
    elseif ($action == "sort_asc") 
    {
        asort($_SESSION['array']);
        $message = "Array sorted in ascending order: " . implode(", ", $_SESSION['array']);
    } 
    elseif ($action == "sort_desc") 
    {
        arsort($_SESSION['array']);
        $message = "Array sorted in descending order: " . implode(", ", $_SESSION['array']);
    } 
    elseif ($action == "sort_no_change") 
    {
        $sorted = $_SESSION['array'];
        sort($sorted);
        $message = "Array sorted by values without changing keys: " . implode(", ", $sorted);
    } 
    elseif ($action == "filter_odds") 
    {
        $filtered = array_filter($_SESSION['array'], function($value) 
        {
            return $value % 2 !== 0;
        });
        
        $message = "Filtered odd elements: " . implode(", ", $filtered);
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <title>Associative Array Operations</title>
</head>
<body>
    <h1>Associative Array Operations</h1>

    <form method="post" action="">
        <label for="array">Enter Array (comma-separated):</label>
        <input type="text" name="array" id="array" required>
        <input type="submit" name="action" value="set_array">
    </form>

    <h2>Choose an Operation:</h2>
    <form method="post" action="">
        <input type="submit" name="action" value="sort_asc">
        <input type="submit" name="action" value="sort_desc">
        <input type="submit" name="action" value="sort_no_change">
        <input type="submit" name="action" value="filter_odds">
    </form>

    <?php
    if (isset($message)) {
        echo "<p>$message</p>";
    }

    echo "<h2>Current Array:</h2>";
    echo "<strong>Array:</strong> " . implode(", ", $_SESSION['array']) . "<br>";
    ?>
</body>
</html>
