<?php
session_start();

if (!isset($_SESSION['arrays'])) 
{
    $_SESSION['arrays'] = [
        'array1' => [5, 3, 8, 1],
        'array2' => [12, 7, 9, 4],
        'array3' => [15, 2, 11, 6]
    ];
}

function sortArrays(&$arrays, $order = 'asc') 
{
    foreach ($arrays as &$array) {
        if ($order === 'asc') {
            sort($array);
        } elseif ($order === 'desc') {
            rsort($array);
        }
    }
}

if ($_SERVER["REQUEST_METHOD"] == "POST") 
{
    $action = $_POST['action'];
    
    if ($action == "sort_asc") 
    {
        sortArrays($_SESSION['arrays'], 'asc');
        $message = "All arrays sorted in ascending order.";
    } 
    elseif ($action == "sort_desc") 
    {
        sortArrays($_SESSION['arrays'], 'desc');
        $message = "All arrays sorted in descending order.";
    }
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <title>Sort Multiple Arrays</title>
</head>
<body>
    <h1>Sort Multiple Arrays</h1>

    <h2>Current Arrays:</h2>
    <?php
    foreach ($_SESSION['arrays'] as $key => $array) 
    {
        echo "<strong>$key:</strong> " . implode(", ", $array) . "<br>";
    }
    ?>

    <h2>Choose an Operation:</h2>
    <form method="post" action="">
        <input type="submit" name="action" value="sort_asc">
        <input type="submit" name="action" value="sort_desc">
    </form>

    <?php
    if (isset($message)) 
    {
        echo "<p>$message</p>";
    }
    ?>
</body>
</html>
