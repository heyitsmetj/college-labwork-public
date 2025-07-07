<?php
session_start(); 

if (!isset($_SESSION['queue'])) 
{
    $_SESSION['queue'] = array();
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $action = $_POST['action'];

    if ($action == "insert") {
        $element = $_POST['element'];
        array_push($_SESSION['queue'], $element);
        $message = "Element '$element' inserted successfully.";
    } elseif ($action == "delete") {
        if (!empty($_SESSION['queue'])) {
            $removedElement = array_shift($_SESSION['queue']);
            $message = "Element '$removedElement' deleted successfully.";
        } else {
            $message = "Queue is empty. No element to delete.";
        }
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <title>Queue Operations</title>
</head>
<body>
    <h1>Queue Operations</h1>

    <form method="post" action="">
        <label for="action">Choose an action:</label>
        <select name="action" id="action">
            <option value="insert">Insert Element</option>
            <option value="delete">Delete Element</option>
        </select>

        <label for="element">Element:</label>
        <input type="text" name="element" id="element" required>

        <input type="submit" value="Submit">
    </form>

    <?php
    if (isset($message)) {
        echo "<p>$message</p>";
    }

    echo "<h2>Current Queue Content:</h2>";
    echo "<pre>";
    print_r($_SESSION['queue']);
    echo "</pre>";
    ?>
</body>
</html>
