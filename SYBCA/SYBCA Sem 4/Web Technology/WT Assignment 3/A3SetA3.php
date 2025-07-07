
<?php

    $myarray = array('a','b','c','d','e','f');

    echo "Original Array: ";
    
    foreach ($myarray as $x)
    {
        echo ($x). ' ';
    }
    
    echo "<br><br>Reversed Array: ";
    foreach (array_reverse($myarray) as $x)
    {
        echo ($x). ' ';
    }
?>