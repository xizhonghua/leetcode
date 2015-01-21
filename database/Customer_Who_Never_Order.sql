SELECT Name 
FROM Customers c WHERE 
    (SELECT COUNT(*) FROM Orders o WHERE o.CustomerId = c.Id) = 0
