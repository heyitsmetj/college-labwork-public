<?php
session_start(); 

if (!isset($_SESSION['stack'])) 
{
    $_SESSION['stack'] = array();
}

if ($_SERVER["REQUEST_METHOD"] == "POST") 
{
    $action = $_POST['action'];

    if ($action == "insert") 
    {
        $element = $_POST['element'];
        array_push($_SESSION['stack'], $element);
        $message = "Element '$element' inserted successfully.";
    } 
    elseif ($action == "delete") 
    {
        if (!empty($_SESSION['stack'])) 
        {
            $removedElement = array_pop($_SESSION['stack']);
            $message = "Element '$removedElement' deleted successfully.";
        } 
        else 
        {
            $message = "Stack is empty. No element to delete.";
        }
    }
}
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <title>Stack Operations</title>
</head>

<body>
    <h1>Stack Operations</h1>

    <form method="post" action="A3SetB2.php">
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

    echo "<h2>Current Stack Content:</h2>";
    echo "<pre>";
    print_r($_SESSION['stack']);
    echo "</pre>";
    ?>
</body>

</html>
