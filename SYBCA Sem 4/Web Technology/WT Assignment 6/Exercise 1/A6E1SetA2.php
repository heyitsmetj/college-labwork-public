<?php

$xml = simplexml_load_file("Teacher.xml");

echo "<h2>Teacher Details</h2>";
echo "<table border='1' cellpadding='5' cellspacing='0'>";
echo "<tr><th>Name</th><th>Qualification</th><th>Subject Taught</th><th>Experience</th></tr>";

foreach ($xml->ComputerScience->Teacher as $teacher) {
    echo "<tr>";
    echo "<td>{$teacher->Name}</td>";
    echo "<td>{$teacher->Qualification}</td>";
    echo "<td>{$teacher->SubjectTaught}</td>";
    echo "<td>{$teacher->Experience}</td>";
    echo "</tr>";
}

echo "</table>";
?>