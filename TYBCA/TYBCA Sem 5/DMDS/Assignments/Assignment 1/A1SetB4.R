companies <- data.frame(
  Shares = c("TCS", "Reliance", "HDFC Bank", "Infosys", "Reliance"),
  Price = c(3200, 1900, 1500, 2200, 1900)
)

cat("Original Data Frame:\n")
print(companies)

cat("\nDuplicate Rows:\n")
print(companies[duplicated(companies),])
