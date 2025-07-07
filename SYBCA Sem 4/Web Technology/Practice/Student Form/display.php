<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    
    $target_dir = "uploads/";
    if (!file_exists($target_dir)) {
        mkdir($target_dir, 0777, true);
    }
    
    $photo = $_FILES["photo"];
    $photo_path = $target_dir . basename($photo["name"]);
    move_uploaded_file($photo["tmp_name"], $photo_path);

    $fullname = htmlspecialchars($_POST["fullname"]);
    $dob = htmlspecialchars($_POST["dob"]);
    $email = htmlspecialchars($_POST["email"]);
    $phone = htmlspecialchars($_POST["phone"]);
    $address = htmlspecialchars($_POST["address"]);
    $course = htmlspecialchars($_POST["course"]);
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <title>Application Letter</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            max-width: 800px;
            margin: 0 auto;
            padding: 20px;
            line-height: 1.6;
        }
        .header {
            text-align: center;
            margin-bottom: 30px;
        }
        .photo {
            float: right;
            max-width: 150px;
            margin: 0 0 20px 20px;
        }
        .student-info {
            margin-bottom: 20px;
        }
        .info-label {
            font-weight: bold;
        }
        .statement {
            margin-top: 30px;
            text-align: justify;
        }
        @media print {
            body {
                padding: 0;
            }
            button {
                display: none;
            }
        }
    </style>
</head>
<body>
    <div class="header">
        <h2>Student Application Letter</h2>
    </div>

    <img src="<?php echo $photo_path; ?>" alt="Student Photo" class="photo">

    <div class="student-info">
        <p><span class="info-label">Full Name:</span> <?php echo $fullname; ?></p>
        <p><span class="info-label">Date of Birth:</span> <?php echo $dob; ?></p>
        <p><span class="info-label">Email:</span> <?php echo $email; ?></p>
        <p><span class="info-label">Phone:</span> <?php echo $phone; ?></p>
        <p><span class="info-label">Address:</span> <?php echo nl2br($address); ?></p>
        <p><span class="info-label">Desired Course:</span> <?php echo $course; ?></p>
    </div>
</body>
</html>
