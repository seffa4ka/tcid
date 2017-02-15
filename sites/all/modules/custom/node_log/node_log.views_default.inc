<?php

/**
 * @file
 * Node log views default file.
 */

/**
 * Implements hook_views_default_views().
 */
function node_log_views_default_views() {

  $view = new view();
  $view->name = 'node_log';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node_log';
  $view->human_name = 'Node log';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'nid' => 'nid',
    'nid_1' => 'nid_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity node log: Node nid */
  $handler->display->display_options['relationships']['node']['id'] = 'node';
  $handler->display->display_options['relationships']['node']['table'] = 'node_log';
  $handler->display->display_options['relationships']['node']['field'] = 'node';
  $handler->display->display_options['relationships']['node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'node';
  /* Field: Entity node log: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node_log';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['path'] = 'admin/config/one-node-log/[nid]';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: COUNT(Entity node log: Nid) */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node_log';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['group_type'] = 'count';
  $handler->display->display_options['fields']['nid_1']['label'] = ' views';
  $handler->display->display_options['fields']['nid_1']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nid_1']['alter']['path'] = 'admin/config/one-node-log/[nid]';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  $views[$view->name] = $view;
  
    $view = new view();
    $view->name = 'one_node_log';
    $view->description = '';
    $view->tag = 'default';
    $view->base_table = 'node_log';
    $view->human_name = 'One node log';
    $view->core = 7;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Master */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'One node log';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['access']['type'] = 'none';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = '10';
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
      'aid' => 'aid',
      'name' => 'name',
      'timestamp' => 'timestamp',
    );
    $handler->display->display_options['style_options']['default'] = '-1';
    $handler->display->display_options['style_options']['info'] = array(
      'aid' => array(
        'sortable' => 0,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'name' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
      'timestamp' => array(
        'sortable' => 1,
        'default_sort_order' => 'asc',
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
    );
    /* Relationship: Entity node log: User ID uid */
    $handler->display->display_options['relationships']['user']['id'] = 'user';
    $handler->display->display_options['relationships']['user']['table'] = 'node_log';
    $handler->display->display_options['relationships']['user']['field'] = 'user';
    /* Field: Entity node log: Entity node log ID */
    $handler->display->display_options['fields']['aid']['id'] = 'aid';
    $handler->display->display_options['fields']['aid']['table'] = 'node_log';
    $handler->display->display_options['fields']['aid']['field'] = 'aid';
    $handler->display->display_options['fields']['aid']['exclude'] = TRUE;
    /* Field: User: Name */
    $handler->display->display_options['fields']['name']['id'] = 'name';
    $handler->display->display_options['fields']['name']['table'] = 'users';
    $handler->display->display_options['fields']['name']['field'] = 'name';
    $handler->display->display_options['fields']['name']['relationship'] = 'user';
    $handler->display->display_options['fields']['name']['label'] = 'USERNAME';
    /* Field: Entity node log: timestamp */
    $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
    $handler->display->display_options['fields']['timestamp']['table'] = 'node_log';
    $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
    $handler->display->display_options['fields']['timestamp']['label'] = 'Created';
    $handler->display->display_options['fields']['timestamp']['date_format'] = 'long';
    $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
    /* Contextual filter: Entity node log: Nid */
    $handler->display->display_options['arguments']['nid']['id'] = 'nid';
    $handler->display->display_options['arguments']['nid']['table'] = 'node_log';
    $handler->display->display_options['arguments']['nid']['field'] = 'nid';
    $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
    $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = TRUE;
    $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

    /* Display: Page */
    $handler = $view->new_display('page', 'Page', 'page');
    $handler->display->display_options['path'] = 'admin/config/one-node-log';

  $views[$view->name] = $view;

  return $views;
}
