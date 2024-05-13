class DoxygenAwesomeTabs {
    static init() {
        window.addEventListener("load", () => {
            document.querySelectorAll(".tabbed:not(:empty)").forEach((tabbed, tabbedIndex) => {
                let tabLinkList = []
                tabbed.querySelectorAll("li").forEach((tab, tabIndex) => {
                    tab.id = "tab_" + tabbedIndex + "_" + tabIndex
                    let header = tab.querySelector(".tab-title")
                    let tabLink = document.createElement("button")
                    tabLink.classList.add("tab-button")
                    tabLink.appendChild(header)
                    tabLink.addEventListener("click", () => {
                        tabbed.querySelectorAll("li").forEach((tab) => {
                            tab.classList.remove("selected")
                        })
                        tabLinkList.forEach((tabLink) => {
                            tabLink.classList.remove("active")
                        })
                        tab.classList.add("selected")
                        tabLink.classList.add("active")
                    })
                    tabLinkList.push(tabLink)
                    if(tabIndex == 0) {
                        tab.classList.add("selected")
                        tabLink.classList.add("active")
                    }
                })
                let tabsOverview = document.createElement("div")
                tabsOverview.classList.add("tabs-overview")
                let tabsOverviewContainer = document.createElement("div")
                tabsOverviewContainer.classList.add("tabs-overview-container")
                tabLinkList.forEach((tabLink) => {
                    tabsOverview.appendChild(tabLink)
                })
                tabsOverviewContainer.appendChild(tabsOverview)
                tabbed.before(tabsOverviewContainer)
            })
        })
    }
}