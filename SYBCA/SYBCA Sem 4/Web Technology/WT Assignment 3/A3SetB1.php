<!DOCTYPE html>
<html lang="en">
<head>
    <title>Multidimensional Array Operations</title>
</head>
<body>
    <h1>Multidimensional Array Operations</h1>
    
    <form method="post" action="A3SetB1.php">
        <label for="action">Choose an action:</label>
        <select name="action" id="action">
            <option value="display">Display Element</option>
            <option value="delete">Delete Element</option>
        </select>
        
        <label for="category">Category:</label>
        <select name="category" id="category">
            <option value="fruits">Fruits</option>
            <option value="vegetables">Vegetables</option>
            <option value="grains">Grains</option>
        </select>
        
        <label for="index">Index:</label>
        <input type="number" name="index" id="index" min="0" required>
        
        <input type="submit" value="Submit">
    </form>

    <?php
    
    $array = array(
        "fruits" => array("apple", "banana", "cherry"),
        "vegetables" => array("carrot", "lettuce", "pepper"),
        "grains" => array("rice", "wheat", "corn")
    );
    
    if ($_SERVER["REQUEST_METHOD"] == "POST") 
    {
        $action = $_POST['action'];
        
        if ($action == "display") 
        {
            $category = $_POST['category'];
            $index = $_POST['index'];
            
            if (isset($array[$category][$index])) 
            {
                $output = "Element: " . $array[$category][$index];
            } 
            else 
            {
                $output = "Invalid category or index.";
            }
        } 
        elseif ($action == "delete") 
        {
            $category = $_POST['category'];
            $index = $_POST['index'];
            
            if (isset($array[$category][$index])) 
            {
                unset($array[$category][$index]);
                $output = "Element deleted successfully.";
            } 
            else 
            {
                $output = "Invalid category or index.";
            }
        }
    }

    if (isset($output)) 
    {
        echo "<p>$output</p>";
    }
    echo "<h2>Current Array Content:</h2>";
    echo "<pre>";
    print_r($array);
    echo "</pre>";
    ?>
</body>
</html>
