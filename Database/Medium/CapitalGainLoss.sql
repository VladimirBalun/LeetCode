SELECT s.stock_name, SUM(IF(s.operation='Buy', -s.price, s.price)) AS capital_gain_loss
FROM Stocks s
GROUP BY s.stock_name
