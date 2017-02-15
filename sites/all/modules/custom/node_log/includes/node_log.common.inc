<?php

/**
 * @file
 * Common file.
 */

/**
 * Extends EntityDefaultMetadataController.
 */
class NodeLogEntityMetadataController extends EntityDefaultMetadataController {

  /**
   * It describes the entity.
   *
   * Linked node_log_entity with node and user. Processing timestamp.
   *
   * @return array
   *   Property info.
   */
  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $info[$this->type]['properties']['node'] = array(
      'label' => t("Node"),
      'type' => 'node',
      'description' => t("Node"),
      'schema field' => 'nid',
    );
    $info[$this->type]['properties']['user'] = array(
      'label' => t("User ID"),
      'type' => 'user',
      'description' => t("User ID"),
      'schema field' => 'uid',
    );
    $info[$this->type]['properties']['timestamp'] = array(
      'label' => t("timestamp"),
      'type' => 'date',
      'description' => t("timestamp"),
      'schema field' => 'timestamp',
      'setter callback' => 'entity_property_verbatim_set',
    );
    return $info;
  }

}

/**
 * Record entity in date base if complies latency.
 *
 * @global type $user
 * @global type $node
 */
function get_log($node) {
  global $user;

  $values = array(
    'nid' => $node->nid,
    'uid'  => $user->uid,
    'timestamp'  => time(),
  );

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node_log_entity');
  $query->propertyCondition('nid', $node->nid);
  $query->propertyCondition('uid', $user->uid);
  $query->propertyOrderBy('aid', 'DESC');
  $query->range(0, 1);
  $checkEntity = $query->execute();

  foreach ($checkEntity['node_log_entity'] as $value) {
    $time = $value->timestamp;
  }

  $latency = variable_get('log_latency');

  if (!$latency) {
    $latency = 60;
  }

  if ($values['timestamp'] - $time > $latency) {
    $entity = entity_create('node_log_entity', $values);
    return entity_save('node_log_entity', $entity);
  }
}
