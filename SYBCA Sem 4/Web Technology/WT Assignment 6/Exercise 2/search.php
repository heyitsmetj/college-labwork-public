<?php
$students = ["Ayush", "Bindu", "Charan", "Dharmesh", "Esha", "Falguni", "Girish", "Hemlata", "Ishika", "Janardhan"];

$query = strtolower($_GET['query'] ?? '');
$results = [];

if ($query === '') {
    exit;
}

foreach ($students as $name) {
    if (stripos($name, $query) === 0) {
        $results[] = $name;
    }
}

if (!empty($results)) {
    echo "<ul>";
    foreach ($results as $name) {
        echo "<li>$name</li>";
    }
    echo "</ul>";
} else {
    echo "<p>No matches found</p>";
}
?>
