<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>Number to Words</title>
</head>
<body>
    <h2>Enter a Number</h2>
    <form method="post">
        <input type="text" name="number" required />
        <input type="submit" value="Show in Words" />
    </form>

    <%
        String num = request.getParameter("number");
        if (num != null) {
            String[] words = {"Zero", "One", "Two", "Three", "Four", "Five",
                              "Six", "Seven", "Eight", "Nine"};
            String result = "";
            if (num.matches("\\d+")) {   // only digits
                for (char c : num.toCharArray()) {
                    result += words[c - '0'] + " ";
                }
                out.println("<h3>In Words: " + result + "</h3>");
            } else {
                out.println("<h3 style='color:red;'>Please enter numbers only!</h3>");
            }
        }
    %>
</body>
</html>
