<h1>🧠 Simulator of Virtual Memory</h1>

<p>
  This is a mini-simulator of a <strong>Virtual Memory Management Unit (MMU)</strong> written in <strong>ANSI C</strong>. 
  The program reads logical addresses from a file (<code>addresses.txt</code>), translates them into physical addresses 
  using a <strong>TLB (Translation Lookaside Buffer)</strong> and a <strong>Page Table</strong>, and handles page faults 
  by fetching data from a simulated disk (<code>BACKING_STORE.bin</code>).
</p>

---

<h2>📊 System Specifications & Assumptions</h2>

<p>The simulator operates under the following architectural constraints and parameters:</p>

<table>
  <thead>
    <tr>
      <th>Parameter</th>
      <th>Value / Size</th>
      <th>Description</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>Virtual Memory Size</strong></td>
      <td>2<sup>16</sup> = 65,536 Bytes</td>
      <td>Total logical address space.</td>
    </tr>
    <tr>
      <td><strong>Physical Memory Size</strong></td>
      <td>2<sup>16</sup> = 65,536 Bytes</td>
      <td>Total physical address space (256 frames × 256 bytes).</td>
    </tr>
    <tr>
      <td><strong>Page / Frame Size</strong></td>
      <td>2<sup>8</sup> = 256 Bytes</td>
      <td>Size of both virtual pages and physical frames.</td>
    </tr>
    <tr>
      <td><strong>Page Table Entries</strong></td>
      <td>2<sup>8</sup> = 256 Entries</td>
      <td>Maps virtual pages to physical frames.</td>
    </tr>
    <tr>
      <td><strong>TLB Size</strong></td>
      <td>16 Entries</td>
      <td>High-speed cache for faster address translation.</td>
    </tr>
    <tr>
      <td><strong>TLB Replacement Policy</strong></td>
      <td>FIFO (First-In, First-Out)</td>
      <td>Algorithm used to evict entries when the TLB is full.</td>
    </tr>
  </tbody>
</table>

<blockquote>
  ℹ️ <strong>Note on Page Replacement:</strong> Since the Physical Memory and Virtual Memory sizes are equal in this simulation, 
  frames will never run out. Therefore, a page replacement algorithm (like LRU or FIFO for frames) is not required when a page fault occurs. 
  The program currently supports <strong>read-only</strong> address translation operations.
</blockquote>

---

<h2>🛠️ Core Functions & API Reference</h2>

<p>The core logic of the simulator is divided into four main functions:</p>

<ul>
  <li>
    <code>void changeaddress()</code>
    <br />
    Reads 32-bit logical addresses from <code>addresses.txt</code>, extracts the 16 least significant bits, and splits them into:
    <ul>
      <li><strong>Page Number:</strong> The upper 8 bits.</li>
      <li><strong>Offset:</strong> The lower 8 bits.</li>
    </ul>
  </li>
  <li>
    <code>int handlePageFault(int page)</code>
    <br />
    Triggered when a page is not found in the Page Table. It performs a random access read from <code>BACKING_STORE.bin</code>, 
    loads the required page into physical memory, and maps it to the correct frame.
  </li>
  <li>
    <code>int TLB_lookup(int page)</code>
    <br />
    Checks if the virtual page is cached in the TLB. Returns the corresponding <code>frame number</code> if a TLB Hit occurs; 
    returns <code>-1</code> if there is a TLB Miss.
  </li>
  <li>
    <code>void insertTLB(int page, int frame)</code>
    <br />
    Inserts a new page-to-frame mapping into the TLB. If the TLB is full, it automatically replaces the oldest entry using the <strong>FIFO</strong> strategy.
  </li>
</ul>

---

<h2>🤝 Contributing & Support</h2>

<p>
  I am the sole creator and maintainer of this project. If you find this simulation helpful, want to give me some advice, 
  or wish to implement improvements (such as adding a page replacement policy for smaller physical memory sizes), 
  <strong>your feedback and
