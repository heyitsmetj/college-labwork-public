<?php
session_start();

if (!isset($_SESSION['array1'])) {
    $_SESSION['array1'] = [];
}
if (!isset($_SESSION['array2'])) {
    $_SESSION['array2'] = [];
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $action = $_POST['action'];

    if ($action == "set_arrays") 
    {
        $_SESSION['array1'] = array_map('trim', explode(',', $_POST['array1']));
        $_SESSION['array2'] = array_map('trim', explode(',', $_POST['array2']));
        $message = "Arrays have been set.";
    } 
    elseif ($action == "merge") 
    {
        $merged = array_merge($_SESSION['array1'], $_SESSION['array2']);
        $message = "Merged Array: " . implode(", ", $merged);
    } 
    elseif ($action == "intersection") 
    {
        $intersection = array_intersect($_SESSION['array1'], $_SESSION['array2']);
        $message = "Intersection: " . implode(", ", $intersection);
    } 
    elseif ($action == "union") 
    {
        $union = array_unique(array_merge($_SESSION['array1'], $_SESSION['array2']));
        $message = "Union: " . implode(", ", $union);
    } 
    elseif ($action == "difference") 
    {
        $difference = array_diff($_SESSION['array1'], $_SESSION['array2']);
        $message = "Set Difference (Array1 - Array2): " . implode(", ", $difference);
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

    <form method="post" action="A3SetC1.php">
        <label for="array1">Enter Array 1 (comma-separated):</label>
        <input type="text" name="array1" id="array1" required>
        
        <label for="array2">Enter Array 2 (comma-separated):</label>
        <input type="text" name="array2" id="array2" required>

        <input type="submit" name="action" value="set_arrays">
    </form>

    <h2>Choose an Operation:</h2>
    <form method="post" action="">
        <input type="submit" name="action" value="merge">
        <input type="submit" name="action" value="intersection">
        <input type="submit" name="action" value="union">
        <input type="submit" name="action" value="difference">
    </form>

    <?php
    if (isset($message)) {
        echo "<p>$message</p>";
    }

    echo "<h2>Current Arrays:</h2>";
    echo "<strong>Array 1:</strong> " . implode(", ", $_SESSION['array1']) . "<br>";
    echo "<strong>Array 2:</strong> " . implode(", ", $_SESSION['array2']) . "<br>";
    ?>
</body>
</html>
