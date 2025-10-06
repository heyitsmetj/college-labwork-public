<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
    <title>Result</title>
</head>
<body>
    <h2>Calculation Result</h2>
    <%
        String n1 = request.getParameter("num1");
        String n2 = request.getParameter("num2");
        String op = request.getParameter("operation");

        if (n1 != null && n2 != null && op != null) {
            try {
                double num1 = Double.parseDouble(n1);
                double num2 = Double.parseDouble(n2);
                double result = 0;

                switch (op) {
                    case "add":
                        result = num1 + num2;
                        out.println("Addition = " + result);
                        break;
                    case "sub":
                        result = num1 - num2;
                        out.println("Subtraction = " + result);
                        break;
                    case "mul":
                        result = num1 * num2;
                        out.println("Multiplication = " + result);
                        break;
                    case "div":
                        if (num2 != 0) {
                            result = num1 / num2;
                            out.println("Division = " + result);
                        } else {
                            out.println("Error: Cannot divide by zero!");
                        }
                        break;
                    default:
                        out.println("Invalid Operation Selected.");
                }
            } catch (NumberFormatException e) {
                out.println("Error: Please enter valid numbers.");
            }
        } else {
            out.println("Error: Missing input or operation.");
        }
    %>
    <br><br>
    <a href="index.html">Go Back</a>
</body>
</html>
