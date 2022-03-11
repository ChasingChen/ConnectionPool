# ConnectionPool
a fully-featured connection pool for MySQL

测试：
<table>
        <tr>
            <th>数据量</th>
            <th>未使用连接池花费时间</th>
            <th>使用连接池花费时间</th>
        </tr>
        <tr>
            <th>1000</th>
            <th>单线程：1459ms 四线程：497ms</th>
            <th>单线程：679ms  四线程：408ms</th>
        </tr>
        <tr>
             <th>5000</th>
            <th>单线程：10033ms 四线程：2461ms</th>
            <th>单线程： 5380ms 四线程：1647ms</th>
        </tr>
        <tr>
              <th>10000</th>
            <th>单线程：19403ms 四线程：4711ms</th>
            <th>单线程：10522ms 四线程：3834ms</th>
        </tr>
<table>




