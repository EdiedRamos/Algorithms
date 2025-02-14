-- Write your PostgreSQL query statement below
select product_name, sum(unit) as unit
from Products, Orders
where Products.product_id = Orders.product_id and order_date between '2020-02-01' and '2020-02-29'
group by product_name
having sum(unit) > 99;
