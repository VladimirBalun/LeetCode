SELECT * FROM (
    SELECT product_id, 'store1' store, store1 AS price FROM Products
    UNION
    SELECT product_id, 'store2' store, store2 AS price FROM Products
    UNION
    SELECT product_id, 'store3' store, store3 AS price FROM Products
) r
WHERE price IS NOT NULL
