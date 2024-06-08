using System.Text;

namespace StateSmith.Output.Sim;

public class HtmlRenderer
{
    public static void Render(StringBuilder stringBuilder, string smName, string mocksCode, string mermaidCode, string jsCode, string diagramEventNamesArray)
    {
        // Now that we are working inside the StateSmith project, we need to restrict ourselves to dotnet 6 features.
        // We can't use """raw strings""" anymore so we do manual string interpolation below string.
        // Also, in the below string, we have to use `""` to escape double quotes. I miss raw strings already...
        string htmlTemplate = @"<!-- 
  -- This file was generated by StateSmith.
  -- It serves as an example of how to use the generated state machine in a web page.
  -- It also serves as an interactive console that you can use to validate the
  -- state machine's behavior.
  --
  -- Using {{smName}}.js generally looks like:
  --   var sm = new {{smName}}();
  --   sm.start();
  --
  -- And then using sm.dispatchEvent() to dispatch events to the state machine.
  -->
<html>
  <head>
    <link rel='icon' type='image/png' href='https://statesmith.github.io/favicon.png'>
    <link rel='stylesheet' href='https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined'>
    <style>
      body {
        display: flex;
        flex-direction: row;
        margin: 0px;
      }

      /* Fix for mermaid content requiring scroll bars https://github.com/StateSmith/StateSmith/issues/288 */
      pre.mermaid {
        margin: 0px;
      }

      .wrapper {
        height: 100vh;
        width: 100vw;
        display: flex;
      }

      .pane {
        padding: 1em;
        min-width: 200px;
      }

      .titlebar-icon {
        font-family: 'Material Symbols Outlined', sans-serif;
        font-size: 16px;
        color: #777;
        border-radius: 5px;
      }

      .gutter {
        width: 10px;
        height: 100%;
        background: #ccc;
        position: absolute;
        top: 0;
        left: 0;
        cursor: col-resize;
      }

      .main {
        flex: 1;
        overflow: auto;
        padding: 10px;
      }

      .sidebar {
        width: 300px;
        padding-top: 0px;
        position: relative;
        background-color: #f0f0f0;
        border-left: 1px solid #ccc;
        display: flex;
        flex-direction: column;
      }

      #buttons {
        display: flex;
        flex-direction: column;
      }

      .titlebar {
        background-color: #ddd;
        border-bottom: 1px solid #ccc;
        font-weight: bold;
        padding: 5px;
        display: flex;
      }

      .console {
        border-collapse: collapse;
        margin-top: 10px;
        width: 100%;
      }

      table.console td.timestamp {
        display: none;
      }

      table.console.timestamps td.timestamp {
        display: table-cell;
      }

      .console th {
        background-color: #f0f0f0;
        border-bottom: 1px solid #ccc;
        font-weight: normal;
        padding: 5px;
        text-align: left;
      }

      .console tbody {
        font-family: monospace;
      }

      .console tr {
        border-bottom: 1px solid #ccc;
      }

      .console td {
        padding: 5px;
      }
  
      .console td.timestamp {
        font-size: small;
      }

      .console td.emphasis {
        font-weight: bold;
        background-color: black;
        color: white;
      }

      .history {
        margin-top: 30px;       
        display: flex;
        overflow: auto;    
        flex-direction: column-reverse;
      }

      .console tr:last-child td {
        border-bottom: none;
      }

      button {
        margin: 5px;
      }

      .dropbtn {
        border: none;
        cursor: pointer;
      }

      .dropbtn:hover, .dropbtn:focus {
        background-color: #f1f1f1;
      }

      .dropdown {
        position: relative;
        display: inline-block;
        margin-left: auto;
      }

      .dropdown-content {
        display: none;
        position: absolute;
        right: 0;
        background-color: #f1f1f1;
        min-width: 160px;
        overflow: auto;
        box-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2);
        z-index: 1;
      }

      .dropdown-content .dropdown-item {
        padding: 12px 16px;
        font-weight: normal;
      }

      .show {display: block;}

      .transition.active {
        stroke: #fff5ad !important;
        stroke-width: 5px !important;
        filter: drop-shadow( 3px 3px 2px rgba(0, 0, 0, .7));
      }

      .statediagram-state.active > * {
        fill: #fff5ad !important;
        stroke-width: 2px !important;
      }

    </style>
  </head>

  <body>
    <div class=""wrapper"">
    <div class=""pane main"">
        <pre class=""mermaid"">
{{mermaidCode}}
        </pre>
    </div>

    <div class=""pane sidebar"">
        <div id=""buttons"">
            <div class=""titlebar"">Events            
              <div class='dropdown'>
                <span id='dropbtn' class='titlebar-icon dropbtn'>settings</span>
                <div id='myDropdown' class='dropdown-content'>
                  <div class='dropdown-item'>
                    <input type='checkbox' id='timestamps' name='timestamps' value='Timestamps'>
                    <label for='timestamps'>Timestamps</label>
                  </div>
                </div>
              </div>            
          </div>
        </div>

        <div class=""history"">
          <table class=""console"">
            <tbody>
            </tbody>
          </table>
        </div>

        <div class=""gutter""></div>
    </div>
    </div>

<script>
{{jsCode}}
</script>

    <script type=""module"">
        import mermaid from 'https://cdn.jsdelivr.net/npm/mermaid@10/dist/mermaid.esm.min.mjs';
        import svgPanZoom from 'https://cdn.jsdelivr.net/npm/svg-pan-zoom@3.6.1/+esm' ;
        mermaid.initialize({ startOnLoad: false });
        await mermaid.run();

        // svg-pan-zoom doesn't like the mermaid viewbox
        document.querySelector('svg').removeAttribute('viewBox');
        document.querySelector('svg').setAttribute('width', '100%');
        document.querySelector('svg').setAttribute('height', '100%');
        document.querySelector('svg').style[""max-width""] = '';

        // don't scale the arrow when we scale the transition edge
        document.querySelectorAll('g defs marker[id$=barbEnd]').forEach(marker => {
            marker.setAttribute('markerUnits', 'userSpaceOnUse');
        });

        var panZoom = window.panZoom = svgPanZoom(document.querySelector('svg'), {
            zoomEnabled: true,
            controlIconsEnabled: true,
            fit: true,
            center: true
        });

        const diagramEventNamesArray = {{diagramEventNamesArray}};

        const leftPane = document.querySelector("".main"");
        const rightPane = document.querySelector("".sidebar"");
        const gutter = document.querySelector("".gutter"");

        function resizer(e) {          
          window.addEventListener('mousemove', mousemove);
          window.addEventListener('mouseup', mouseup);          
          let prevX = e.x;
          const rightPanel = rightPane.getBoundingClientRect();
                    
          function mousemove(e) {
            let newX = prevX - e.x;
            rightPane.style.width = rightPanel.width + newX + 'px';
            window.panZoom.resize();
            window.panZoom.fit();
            window.panZoom.center();
          }
          
          function mouseup() {
            window.removeEventListener('mousemove', mousemove);
            window.removeEventListener('mouseup', mouseup);
            
          }                  
        }

        gutter.addEventListener('mousedown', resizer);

        document.getElementById('timestamps').checked = document.querySelector('table.console').classList.contains('timestamps');
        document.getElementById('timestamps').addEventListener('change', function() {
          if(this.checked) {
            document.querySelector('table.console').classList.add('timestamps');
          } else {
            document.querySelector('table.console').classList.remove('timestamps');
          }
        });

        document.getElementById('dropbtn').addEventListener('click', myFunction);

        /* When the user clicks on the button, 
        toggle between hiding and showing the dropdown content */
        function myFunction() {
          document.getElementById('myDropdown').classList.toggle('show');
        }

        // Close the dropdown if the user clicks outside of it
        window.onclick = function(event) {
          if (!event.target.matches('.dropbtn')) {
            var dropdowns = document.getElementsByClassName('dropdown-content');
            var i;
            for (i = 0; i < dropdowns.length; i++) {
              var openDropdown = dropdowns[i];
              if (openDropdown.classList.contains('show')) {
                openDropdown.classList.remove('show');
              }
            }
          }
        }


{{mocksCode}}

        // Convert a date to a string in the format HH:MM:SS.sss
        function formatTime(date) {
            return date.getHours().toString().padStart(2, '0') + ':' +
                date.getMinutes().toString().padStart(2, '0') + ':' +
                date.getSeconds().toString().padStart(2, '0') + '.' +
                date.getMilliseconds().toString().padStart(3, '0');
        }

        // Add a row to the history table.
        function addHistoryRow(time, event, emphasis = false) {
            var row = document.createElement('tr');
            var timeCell = document.createElement('td');
            timeCell.innerText = formatTime(time);
            timeCell.classList.add('timestamp');
            var eventCell = document.createElement('td');
            eventCell.innerText = event;
            if(emphasis) {
                eventCell.classList.add('emphasis');                
            }
            row.appendChild(timeCell);
            row.appendChild(eventCell);
            document.querySelector('tbody').appendChild(row);
        }

        var sm = new {{smName}}();

        // prompt the user to evaluate guards manually
        sm.evaluateGuard = (guard) => {
            return confirm('Evaluate guard: ' + guard);
        }; 

        const highlightedEdges = new Set();
        function highlightEdge(edgeId) {
            var edge = document.getElementById(edgeId);
            if (edge) {
              edge.classList.add('active');
              highlightedEdges.add(edge);
            }
        }

        function clearHighlightedEdges() {
            for (const edge of highlightedEdges) {
              edge.classList.remove('active');
              const showOldTraversal = false;
              if (showOldTraversal) {
                  // shows that the edge was traversed. Optional, but kinda nice.
                  edge.style.stroke = 'green';
              }
            }
            highlightedEdges.clear();
        }

        // The simulator uses a tracer callback to perform operations such as 
        // state highlighting and logging. You do not need this functionality
        // when using {{smName}}.js in your own applications, although you may
        // choose to implement a tracer for debugging purposes.
        sm.tracer = {
            enterState: (mermaidName) => {
                var e = document.querySelector('g[data-id=' + mermaidName + ']');
                if(e) {
                  e.classList.add('active');
                  panOnScreen(e);
                }
                sm.tracer.log('➡️ Entered ' + mermaidName);
            },
            exitState: (mermaidName) => {
                document.querySelector('g[data-id=' + mermaidName + ']')?.classList.remove('active');
            },
            edgeTransition: (edgeId) => {
                highlightEdge(edgeId);
            },
            log: (message, emphasis=false) => {
                addHistoryRow(new Date(), message, emphasis);
            }
        };

        // Wire up the buttons that dispatch events for the state machine.
        diagramEventNamesArray.forEach(diagramEventName => {
            var button = document.createElement('button');
            button.id = 'button_' + diagramEventName;
            button.innerText = diagramEventName;
            button.addEventListener('click', () => {
                clearHighlightedEdges();
                sm.tracer?.log(""Dispatched "" + diagramEventName, true);
                const fsmEventName = diagramEventName.toUpperCase();
                sm.dispatchEvent({{smName}}.EventId[fsmEventName]); 
            });
            document.getElementById('buttons').appendChild(button);
        });

        sm.tracer?.log('Start', true);
        sm.start();


        function panOnScreen(element) {
          if(!element) return;

          var bounds = element.getBoundingClientRect();
          if(bounds.x<0 || bounds.y<0) {
              var x = Math.max(0, -bounds.x + 20);
              var y = Math.max(0, -bounds.y + 20);
              window.panZoom.panBy({x: x, y: y});
          }
          var panebounds = document.querySelector('svg').getBoundingClientRect();
          if(bounds.x>panebounds.width || bounds.y>panebounds.height) {
              var x = Math.min(0, panebounds.width - bounds.x - bounds.width - 20);
              var y = Math.min(0, panebounds.height - bounds.y - bounds.height - 20);
              window.panZoom.panBy({x: x, y: y});
          }
        }
    </script>


  </body>
</html>";

        htmlTemplate = htmlTemplate.Replace("{{mermaidCode}}", mermaidCode);
        htmlTemplate = htmlTemplate.Replace("{{jsCode}}", jsCode);
        htmlTemplate = htmlTemplate.Replace("{{mocksCode}}", mocksCode);
        htmlTemplate = htmlTemplate.Replace("{{smName}}", smName);
        htmlTemplate = htmlTemplate.Replace("{{diagramEventNamesArray}}", diagramEventNamesArray);
        stringBuilder.AppendLine(htmlTemplate);
    }
}
