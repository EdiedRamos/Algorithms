-- * 183. Customers Who Never Order

SELECT Customers.name as Customers
FROM Customers
LEFT JOIN Orders
ON Orders.customerId = Customers.id
WHERE Orders.id IS NULL;